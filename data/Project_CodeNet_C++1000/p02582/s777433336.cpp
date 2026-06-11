#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int ans=0;
    int k=0;
    for(int i=0;i<3;i++){
        if(s.at(i)=='R'){
            k++;
        }else{
            ans=max(ans,k);
            k=0;
        }
    }
    cout<<max(ans,k)<<endl;
    return 0;
}