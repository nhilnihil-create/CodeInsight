#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, k; cin >> n >> k;
	int arr[n+1];
	for (int i = 1; i <= n; i++)
	    cin >> arr[i];
	int A[n+2];
	int count = 0; bool f = true;
	while (count < k && f)
	{
	    memset(A, 0, sizeof(A));
	    for (int i = 1; i <= n; i++)
	    {
	        A[max(i - arr[i], 1)]++;
	        A[min(n+1, i + arr[i] + 1)]--;
	    }
	    f = false;
	    arr[1] = A[1];
	    if (arr[1] != n)
	        f = true;
	    for (int i = 2; i <= n; i++)
	    {
	        arr[i] = A[i] + arr[i-1];
	        if (arr[i] != n)
	            f = true;
	    }
	    count++;
	}
	cout << arr[1];
	for (int i = 2; i <= n; i++)
	    cout << " " << arr[i];
	cout << '\n';
	
    return 0;
}