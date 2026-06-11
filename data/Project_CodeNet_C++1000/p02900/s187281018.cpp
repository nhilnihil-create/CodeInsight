#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<n;i++)

int A, B;
set<int> SA, SB;

signed main()
{
    cin >> A >> B;

    SA.insert(1);
    SB.insert(1);

    for(int i = 2; i <= 1000000; i++)
    {
        while (A % i == 0)
        {
            SA.insert(i);
            A /= i;
        }
        
        while(B % i == 0)
        {
            SB.insert(i);
            B /= i;
        }
    }
    SA.insert(A);
    SB.insert(B);

    vector<int> v;
    set_intersection(SA.begin(), SA.end(), SB.begin(), SB.end(), back_inserter(v));

    cout << v.size() << endl;

    return 0;
}