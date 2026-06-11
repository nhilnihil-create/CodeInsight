
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1e9 + 7
#define mx 1000000000
#define endl '\n'

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<string> s(n);
    for(int i = 0;i<n;i++){
        cin>>s[i];
    }
    int ans = 0;
    int arr[n][m],brr[n][m];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(s[i][j] == '.')arr[i][j] = 1,brr[i][j] = 1;
            else arr[i][j] = 0,brr[i][j] = 0;
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 1;j<m;j++){
            if(s[i][j] != '#'){
                arr[i][j] += arr[i][j-1];
            }
        }
    }
    for(int i = 0;i<m;i++){
        for(int j = 1;j<n;j++){
            if(s[j][i] != '#'){
                brr[j][i] += brr[j-1][i];
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = m-2;j>=0;j--){
            if(s[i][j+1] != '#' && s[i][j] != '#'){
                arr[i][j] = arr[i][j+1];
            }
        }
    }

    for(int i = 0;i<m;i++){
        for(int j = n-2;j>=0;j--){
            if(s[j+1][i] != '#' && s[j][i] != '#'){
                brr[j][i] = brr[j+1][i];
            }
        }
    }

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            ans = max(ans,arr[i][j] + brr[i][j]);
        }
    }

    cout<<ans-1;
    return 0;
}

