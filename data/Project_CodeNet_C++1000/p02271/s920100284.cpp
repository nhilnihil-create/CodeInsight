#include <iostream>
#include <string>
#include <vector>

using namespace std;

//index??\??????????´?????????£???m???????????????
bool Solve(int index, int m, const vector<int>& A)
{
    if(index >= A.size()) return false;
    if(m == 0) return true;

    return Solve(index + 1, m, A) || Solve(index + 1, m - A[index], A);
}


int main() {
    int n;
    cin >> n;

    vector<int> A(n + 1);
    for(int i = 0, input; i < n && cin >> input; ++i)
        A[i] = input;

    int q;
    cin >> q;
    for(int i = 0; i < q; ++i)
    {
        int m;
        cin >> m;

        cout << (Solve(0, m, A) ? "yes" : "no") << endl;
    }


    return 0;
}