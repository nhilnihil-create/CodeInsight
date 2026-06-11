#include<bits/stdc++.h>
using namespace std;

int main(){

    long long int n,i;
    cin >> n;
    string S[n];

    for(i=0;i<n;i++) {
        cin >> S[i];
        sort(S[i].begin(), S[i].end());
    }

    sort(S, S+n);

    long long int count =0, ans=0;
    for(i=0;i<n-1;i++){
        if(S[i]==S[i+1])
            count++;
        else{
            ans += count*(count+1)/2;
            count = 0;
        }
    }

    if(count!=0)
        ans+= count*(count+1)/2;

    cout << ans << endl;
    
    return 0;
}