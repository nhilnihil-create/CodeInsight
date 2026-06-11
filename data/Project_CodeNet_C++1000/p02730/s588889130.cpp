#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    while(cin>>s){
        bool pal=1;
        for(int i=0,j=(int)s.size()-1;i<(int)s.size();i++,j--){
            if(s[i]!=s[j]){
                pal=0;
                break;
            }
        }
        if(!pal){
            cout << "No\n";
        }
        else{
            for(int i=0,j=(((int)s.size()-1)/2)-1;i<((int)s.size()-1)/2;i++,j--){
                if(s[i]!=s[j]){
                    pal=0;
                    break;
                }
            }
            if(!pal){
                cout << "No\n";
            }
            else{
                for(int i=(((int)s.size()+3)/2)-1,j=(int)s.size()-1;i<s.size();i++,j--){
                    if(s[i]!=s[j]){
                        pal=0;
                        break;
                    }
                }
                if(!pal){
                    cout << "No\n";
                }
                else {
                    cout << "Yes\n";
                }
            }
        }
    }
    return 0;
}
