#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N + 1);//葉の数
  
  int64_t D = 0;//Dは分岐点の数
  int64_t T = 0;//深さiの頂点数
  int64_t P = 1;//深さi+1の頂点数
  bool imp = false;//２分木がつくれないときtrue
  
  for(int i = 0; i < N + 1; i++)
  {
    cin >> A.at(i);
    D += A.at(i);
  }
  
  D--;
  
  //ここまでOK
  
  for(int j = 0; j < N + 1; j++)
  {
    T += P;
    P -= A.at(j);//深さjで分岐できる頂点の数
    if(P < 0)
    {
      imp = true;
      break;
    }
    if(D >= P)
    {
      D -= P;
      P *= 2;
    }
    else
    {
      P += D;
      D = 0;
    }
  }
  
  if(imp){cout << "-1" << endl;}
  else{cout << T << endl;}
}