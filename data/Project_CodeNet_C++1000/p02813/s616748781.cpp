#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> P(N);
    vector<int> Q(N);
    for (int i=0; i<N; i++) cin >> P[i];
    for (int i=0; i<N; i++) cin >> Q[i];
    vector<int> tmp(N);
    for (int i=1; i<=N; i++) tmp[i-1] = i;

    int p=-1;
    int q=-1;
    int id=0;
    do
    {
        id++;
        if (P==tmp) p=id;
        if (Q==tmp) q=id;
    }while(next_permutation(tmp.begin(), tmp.end()));
    cout << abs(p-q) << endl;
}