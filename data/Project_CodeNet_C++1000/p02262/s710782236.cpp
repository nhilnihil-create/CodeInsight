/**
 *  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_A
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

vector<int>
insersionsort(const vector<int> a, const int g, int &cnt)
{
    vector<int> work(a);
    for (int i = g; i < work.size(); i++) {
        int v = work[i];
        int j = i - g;
        while (j >= 0 && work[j] > v) {
            work[ j + g ] = work[j];
            j = j - g;
            cnt++;
        }
        work[ j + g ] = v;
    }
    return work;
}

void
shellsort(const vector<int> a)
{
    vector<int> work(a);
    int cnt = 0;
    int m = 1;
    vector<int> gs;
    while (pow(3, m) < 2 * a.size() + 2) { 
        gs.push_back((pow(3, m) - 1) / 2);
        m++;
    }

    cout << gs.size() << endl;

    for (auto it = gs.crbegin(); it != gs.crend(); it++) {
        if (it != gs.crbegin()) { cout << ' '; }

        vector<int> w = insersionsort(work, *it, cnt);
        cout << *it;
        work.swap(w);
    }
    cout << endl;
    cout << cnt << endl;

    for (auto it : work) {
        cout << it << endl;
    }
}

int
main()
{
    int N;
    cin >> N; cin.ignore();

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i]; cin.ignore();
    }
    shellsort(A);

    return 0;
}