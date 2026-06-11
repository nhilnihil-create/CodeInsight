#include <iostream>
using namespace std;
  int n;
void equival(char *out,int i,char ch)
{
if(i==n)
{
    out[i] = '\0';
    cout<<out<<endl;
    return;
}

for(char c = 'a' ;c<=ch;c++)
{
    out[i] = c;
    if(c==ch)
    {
        equival(out,i+1,ch+1);
    }else
    {
         equival(out,i+1,ch);
    }
}



}
int main() {

  cin>>n;
  char out[1000];
  equival(out,0,'a');
}
