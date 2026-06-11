 #include<bits/stdc++.h>
using namespace std;
int main()
  {
  char ch[4];
  cin>>ch;
  sort(ch,ch+4);
  
    if((ch[0]==ch[1])&&(ch[1]!=ch[2])&&(ch[2]==ch[3]))
      {
      cout<<"Yes"<<endl;
      }
    else
      {
      cout<<"No"<<endl;
      }
  }
