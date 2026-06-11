 #include<bits/stdc++.h>
using namespace std;
int main()
{
    char ch[3];
    int count = 0;
    cin>>ch;
    for(int i = 0;i<3;i++)
    {
      if(ch[i]=='7')
      count++;
     
    }
    if(count==0)
    cout<<"No"<<endl;
    else
    cout<<"Yes"<<endl;
}