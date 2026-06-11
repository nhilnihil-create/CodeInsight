#include <iostream>
#include <vector>
using namespace std;

#define STRING_LIMIT 1000

void Input(vector<char> &);
int EditDistance(vector<char> &, vector<char> &);

int main()
{
  int e_dist; //編集距離
  vector<char> s_buf; //文字列S
  vector<char> t_buf; //文字列T
  
  /* 入力 */
  Input(s_buf);
  Input(t_buf);
  
  /* 編集距離計算 */
  e_dist = EditDistance(s_buf, t_buf);

  /* 出力 */
  cout << e_dist << endl;
  
  return 0;
}

void Input(vector<char> &buf)
{
  	char c;
    int i,ret;
  
	for(i=0 ; i < STRING_LIMIT+1 ; i++)
    {
    	ret = scanf("%c",&c);
    	if( c == '\n' || ret == EOF ) break;
        else buf.push_back(c);
    }
}

int EditDistance(vector<char> &str1, vector<char> &str2)
{
    int i,j;
  	int e_dist = STRING_LIMIT; //編集距離
    int count = 0;
    int str1_len = str1.size();
    int str2_len = str2.size();
    
  	for(i=0 ; i < (str1_len-str2_len+1) ; i++)
    {
    	for(j=0 ; j < str2_len ; j++)
        {
        	if( str1[i+j] != str2[j] ) count++;
        }
        if( count < e_dist )
        {
        	e_dist = count;
        }
        count = 0;
    }
  	
    return e_dist;
}