#include <bits/stdc++.h>
using namespace std;

int main()
{
    int K, N, lastto = 0, distance=0, where = -1, dochu = 0;
    cin >> K >> N;
    vector<int> A(N);
    vector<int> vec(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A.at(i);

        if (i >= 1 && distance <= A.at(i) - A.at(i - 1))
        {
            distance = A.at(i) - A.at(i - 1);
            where = i;
        }
    }
    if(distance<K-A.at(N-1)+A.at(0))
    {
        where = -1;
    }

    lastto = K - A.at(N - 1) + A.at(0);

    for (int i = 1; i < N; i++)
    {
        if (i != where)
        {
            dochu = dochu+ A.at(i) - A.at(i - 1);
            //cout << dochu << endl;
            //cout << lastto << endl;
        }
    }

    if (where == -1)
    {
        cout << A.at(N-1)-A.at(0)<< endl;
    }
    else
    {
        cout  << dochu+lastto << endl;
    }
}
