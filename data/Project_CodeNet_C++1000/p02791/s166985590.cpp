#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,i;
    cin >> N;
    vector<int> p(N);
    for(i=0; i<N; i++){
        cin >> p.at(i);
    }

    int m=200000;
    int cnt =0;
    for(i=0; i<N; i++){
        if(p.at(i) <= m){
            m = p.at(i);
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}