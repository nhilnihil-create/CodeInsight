#include<bits/stdc++.h>
#define ll long long
using namespace std;
void CountTriangles(vector<int> arr)
{

    int n = arr.size();

    sort(arr.begin(), arr.end());

    int count = 0;

    for (int i = n - 1; i >= 1; i--) {
        int l = 0, r = i - 1;
        while (l < r) {
            if (arr[l] + arr[r] > arr[i]) {

                count += r - l;
                r--;
            }
            else
                l++;
        }
    }
    cout<< count;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){cin>>arr[i];}
    CountTriangles(arr);


}
