#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    map<int, int> Q;
    int A, B;
    for (int i = 0; i < N; i++)
    {
        cin >> A >> B;
        Q[B] += A;
    }

    int t = 0;
    for (auto& p : Q)
    {
        t += p.second;
        if (t > p.first)
        {
            cout << "No" << endl;
            return 0;
        }

    }
    
    cout << "Yes" << endl;

    return 0;
}