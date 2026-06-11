#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{
    int N,cnt = 0;
    cin >> N;

    vector<int> l(N);
    rep(i, N) 
        cin >> l[i];

    sort(l.begin(),l.end());
    for(int i = 0;i < N;i++){
        for(int j = i+1;j < N;j++){
            for(int k = j+1;k < N;k++){
                if(l[i] != l[j] && l[i] != l[k] && l[j] != l[k] && l[k] <l[i]+l[j])
                    cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}