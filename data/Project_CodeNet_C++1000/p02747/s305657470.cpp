#include<iostream>

using namespace std;
int main()
{
    string s;
    cin>>s;
    int j=0,s1=0,s2=0;
    while(s[j]!='\0'){
          if(s[j]!='h' && s[j]!='i'){
             cout<<"No"<<endl;

             return 0;
          }
          if(s[j]=='h'){
             s1++;
             if(s1!=s2+1){
                ///cout<<s1<<" "<<s2+1<<endl;
                cout<<"No"<<endl;

                return 0;
             }
          }
          if(s[j]=='i'){
             s2++;
             ///cout<<s2<<endl;
             if(s2!=s1){
                cout<<"No"<<endl;

                return 0;
             }
          }
       j++;
    }
    ///cout<<s1<<" "<<s2<<endl;
    if(s1==s2){
       cout<<"Yes"<<endl;
    }
    else{
       cout<<"No"<<endl;
    }


    return 0;
}
