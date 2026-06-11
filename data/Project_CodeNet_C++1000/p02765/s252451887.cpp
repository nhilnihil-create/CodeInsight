#include <iostream>
using namespace std;
#define fin(ans) cout << (ans) << '\n'
int main()
{
    int N,R;
    cin >> N >> R;
    fin((N < 10)? R+100*(10-N) : R  );
    return 0;
}