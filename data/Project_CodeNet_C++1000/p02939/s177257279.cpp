#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

int main(){
    string s;cin>>s;
    int ans=s.size();
    char c;
    c=s[0];
    int flag=0;
    for(int i=1;i<s.size();i++){
        if(flag==i){
            c='A';
            continue;
        }
        if(c==s[i]){
            flag=i+1;
            ans--;
            c='A';
        }
        c=s[i];
    }
    cout<<ans<<endl;
}