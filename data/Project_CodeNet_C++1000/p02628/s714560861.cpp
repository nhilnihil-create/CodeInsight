#include <iostream>
#include <vector>
using namespace std;
int partition2(vector<int> &a, int l, int r) {
    int x = a[l];
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] <= x) {
            j++;
            swap(a[i], a[j]);
        }
    }
    swap(a[l], a[j]);
    return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
    if (l >= r) {
        return;
    }
    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    int m = partition2(a, l, r);

    randomized_quick_sort(a, l, m - 1);
    randomized_quick_sort(a, m + 1, r);
}
int min(int n,int k,vector<int>&p)
{
    int ans=0;
    randomized_quick_sort(p,0,n-1);
    for (int i = 0; i <k ; ++i) {
        ans+=p[i];
    }
    return ans;
}
int main() {
    int n,k;
    cin>>n>>k;
    vector<int> p(n);
    for (int i = 0; i <n ; ++i) {
        cin>>p[i];
    }
    cout<<min(n,k,p)<<endl;
}
