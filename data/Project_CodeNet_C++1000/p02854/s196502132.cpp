#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define ALL(A) A.begin(),A.end()

int main()
{
    int N;
    cin >> N;

    vector<ll> A(N);
    vector<ll> dif(N-1);
    for(int i=0;i<N;i++)
    {
        cin >> A.at(i);
    }
    ll all = accumulate(ALL(A),0LL);
    for(int i=0;i<N-1;i++)
    {
        all -= 2 * A.at(i); 
        dif.at(i) = abs(all);
    }

    ll mindif = *min_element(ALL(dif));

    cout << mindif << endl;

    return 0;
}