#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    int num,a,b;
    char c;
    string str,meirei,p,ans;
    cin>>str>>num;
    for(int i=0;i<num;i++){
        cin>>meirei>>a>>b;
        if(meirei=="print"){
            for(int j=a;j<=b;j++){
                cout<<str[j];
            }
            cout<<endl;
        }else if(meirei=="reverse"){
            for(int j=0;j<str.size();j++){
                if(a<=j&&j<=b){
                    for(int k=b;k>=a;k--){
                        c=str[k];
                        ans+=c;
                    }
                    j=b;
                }else{
                    c=str[j];
                    ans+=c;
                }
            }
            swap(str,ans);
            ans="";
        }else{
            cin>>p;
            for(int j=0;j<=str.size();j++){
                if(a<=j&&j<=b){
                    for(int k=0;k<p.size();k++){
                        c=p[k];
                        ans+=c;
                    }
                    j=b;
                }else{
                    c=str[j];
                    ans+=c;
                }
            }
            swap(str,ans);
            ans="";
        }
    }
    return 0;
}