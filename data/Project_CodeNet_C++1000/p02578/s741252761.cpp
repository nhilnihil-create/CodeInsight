#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vint;
typedef vector<vint> vvint;

static int n;
static vint arr;

long long solve(void){
    long long res = 0;

    for(int i = 1; i < n; i++){
        if(arr[i] < arr[i-1]){
            res += arr[i-1] - arr[i];
            arr[i] = arr[i-1];
        }
    }

    return res;
}

int main()
{
	while(cin >> n){
		arr.resize(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        cout << solve() << "\n";
	}
	
	return 0;
}
