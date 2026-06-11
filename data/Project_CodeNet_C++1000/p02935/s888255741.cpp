#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<double> A(N);
    for(int i=0; i<N; i++)
    {
        cin >> A.at(i);
    }
    sort(A.begin(),A.end());
    for(int i=1; i<N; i++)
    {
        A.at(i)+=A.at(i-1);
        A.at(i)/=2;
    }
    cout << setprecision(10) << fixed << A.at(N-1) << endl;
    
}
