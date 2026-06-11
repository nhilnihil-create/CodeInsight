#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifdef TarekHasan
    freopen("input.txt","r",stdin);
#endif // TarekHasan
    int x,y,a,b,c;
    cin >> x >> y >> a >> b >> c;

    vector< int > A(a);
    vector< int > B(b);
    vector< int > C(c);

    for(int i=0; i<a; i++)
        cin >> A[i];
    for(int i=0; i<b; i++)
        cin >> B[i];
    for(int i=0; i<c; i++)
        cin >> C[i];


    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());

    vector< int > Final;

    for(int i=0;i<x;i++)
        Final.push_back(A[i]);
    for(int i=0;i<y;i++)
        Final.push_back(B[i]);
    for(int i=0;i!=C.size();i++)
        Final.push_back(C[i]);

    sort(Final.begin(),Final.end(),greater<int>());

    long long int result = 0;

    for(int i=0;i<x+y;i++)
        result+=Final[i];
    cout << result << endl;




    return 0;
}
