#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int main(void)
{
    long long N;
    set<string> st;
    cin >> N;
    for (long long i = 0; i < N; ++i)
    {
        string tmp;
        cin >> tmp;
        st.insert(tmp);
    }
    cout << st.size();
}
