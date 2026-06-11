#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;
int main() {
    int N;
    cin>>N;
    int ans=0;
    int tmp=0;
    int prev=0;
    for (int i = 0; i < N; i++){
        int h;
        cin>>h;
        if(prev>=h){
            tmp++;
            ans=max(ans,tmp);
        }else tmp=0;
        prev=h;
    }
    cout<<ans<<endl;
}