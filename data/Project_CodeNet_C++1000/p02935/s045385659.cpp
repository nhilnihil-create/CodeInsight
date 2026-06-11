#include<bits/stdc++.h>
#define mod pow(10,9)+7
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>

#define mii map<int,int>
#define int long long
#define inf 2000000000000000000
#define re(i,x,n) for(i=x;i<=n;i++)

using namespace std;
#define int long long
void c_p_c()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef  ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
// struct edge
// {
// 	int a;
// 	int b;
// 	int w;
// };
// edge ar[100000];
// int par[10001];
// bool comp(edge a, edge b)
// {
// 	if (a.w < b.w)
// 		return true;
// 	else
// 		return false;
// }
// int find(int a)
// {
// 	if (par[a] == -1)
// 		return a;
// 	else
// 		return par[a] = find(par[a]);
// }
// void merge(int a, int b)
// {
// 	par[a] = b;
// }
//
int maxProductSubarrayOfSizeK(int A[], int n, int k)
{
	// sorting given input array
	sort(A, A + n);

	// variable to store final product of all element
	// of sub-sequence of size k
	int product = 1;

	// CASE I
	// If max element is 0 and
	// k is odd then max product will be 0
	if (A[n - 1] == 0 && (k & 1))
		return 0;

	// CASE II
	// If all elements are negative and
	// k is odd then max product will be
	// product of rightmost-subarray of size k
	if (A[n - 1] <= 0 && (k & 1)) {
		for (int i = n - 1; i >= n - k; i--)
			product *= A[i];
		return product;
	}

	// else
	// i is current left pointer index
	int i = 0;

	// j is current right pointer index
	int j = n - 1;

	// CASE III
	// if k is odd and rightmost element in
	// sorted array is positive then it
	// must come in subsequence
	// Multiplying A[j] with product and
	// correspondingly changing j
	if (k & 1) {
		product *= A[j];
		j--;
		k--;
	}

	// CASE IV
	// Now k is even
	// Now we deal with pairs
	// Each time a pair is multiplied to product
	// ie.. two elements are added to subsequence each time
	// Effectively k becomes half
	// Hence, k >>= 1 means k /= 2
	k >>= 1;

	// Now finding k corresponding pairs
	// to get maximum possible value of product
	for (int itr = 0; itr < k; itr++) {

		// product from left pointers
		int left_product = A[i] * A[i + 1];

		// product from right pointers
		int right_product = A[j] * A[j - 1];

		// Taking the max product from two choices
		// Correspondingly changing the pointer's position
		if (left_product > right_product) {
			product *= left_product;
			i += 2;
		}
		else {
			product *= right_product;
			j -= 2;
		}
	}

	// Finally return product
	return product;
}
int32_t main()
{

	

	int n;
	cin >> n;
	double a[n];
	int i;
	for (i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);

	double sum = 0;
	int temp = n - 1;
	i = 0;
	double maxi = INT_MIN;
	while (temp--)
	{
		sum = (a[i] + a[i + 1]) / 2;
		a[i + 1] = sum;
		maxi = max(maxi, sum);
		i++;
	}
	cout << maxi;

}
