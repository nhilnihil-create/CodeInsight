#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N),Acopy(N),ans(N);
    for (int i = 0; i < N;i++)
    {
        cin >> A.at(i);
        Acopy.at(i) = A.at(i);
    }
    sort(A.begin(), A.end());

    for (int i = 0; i < N; i++)
    {
        if(Acopy.at(i)!=A.at(N-1))
        {
            ans.at(i) = A.at(N-1);
        }else
        {
            ans.at(i) = A.at(N - 2);
        }
        cout << ans.at(i) << endl;
    }
}
