#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    int pre;
    cin >> pre;
    ll sum = 0;
    for(int i = 1; i < n; ++i)
    {
        int nxt;
        cin >> nxt;
        if(nxt < pre)
        {
            sum += (pre - nxt);
            pre = (pre-nxt);
            pre += nxt;
        }
        else
        {
            pre = nxt;
        }
    }
    cout << sum;
	return 0;
}