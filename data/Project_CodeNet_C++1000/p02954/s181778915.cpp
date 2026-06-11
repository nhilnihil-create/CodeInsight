#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    string S;
    cin >> S;

    int N = S.size();
    vector<int> r(N,0), l(N,0);
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if(S[i] == 'R'){
            cnt++;
        } else {
            r[i] = cnt;
            cnt = 0;
        }
    }
    cnt = 0;
    for (int i = N-1; i >=0; i--)
    {
        if(S[i] == 'L'){
            cnt++;
        } else {
            l[i] = cnt;
            cnt = 0;
        }
    }

    for (int i = 1; i < N; i++)
    {
        if(r[i] > 0){
            int r_i = r[i];
            r[i] = r[i]/2;
            r[i-1] = r_i - r[i];
        }
    }

    for (int i = N-2; i >= 0; i--)
    {
        if(l[i] > 0){
            int l_i = l[i];
            l[i] = l[i]/2;
            l[i+1] = l_i - l[i];
        }
    }
    
    for(int i = 0; i < N; i++){
        cout << l[i] + r[i] <<' ';
    }
    cout << endl;
    return 0;
}
