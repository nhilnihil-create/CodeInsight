#include<bits/stdc++.h>
using namespace std;
int main(){
    set<char>c;
    set<char>::iterator itr;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        c.insert(s.at(i));
    }
    if(c.size()==2){
        int check1=0;
        for(itr=c.begin();itr!=c.end();itr++){
            char ch=*itr;
            int check=0;
            for(int i=0;i<s.size();i++){
                if(ch==s.at(i)){
                    check++;
                }
            }
            if(check==2){
                continue;
            }
            else{
                check1++;
                cout<<"No"<<endl;
                return 0;
            }
        }
    if(check1==0){
        cout<<"Yes"<<endl;
    }

    }
    else{
        cout<<"No"<<endl;
    }


}
