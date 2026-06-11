#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;
int main() {
    int N;
    cin>>N;
    vector<bool> a(N);
    for (int i = 0; i < N; i++){
        int x;cin>>x;
        a[i]=x;
    }
    vector<bool> ans(N);
    int M=0;
    for(int i=N; i>0; i--){
        int sum=0;
        int j=i+i;
        while(j<=N){
            sum+=(int)ans[j-1];
            j+=i;
        }
        if((sum%2==0)==(!a[i-1]))ans[i-1]=0;
        else {
            ans[i-1]=1;
            M++;
        }
    }
    cout<<M<<endl;
    for (int i = 0; i < N; i++)if(ans[i])cout<<i+1<<endl;
}