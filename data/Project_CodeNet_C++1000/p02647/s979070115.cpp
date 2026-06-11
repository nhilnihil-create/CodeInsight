#include<iostream>
#include<vector>

using namespace std;
typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++)    cin >> a[i];
    
    for(int kk = 0 ;kk < min(k, 50); kk++)
    {
      	vector<int> fre(n, 0);
        for(int j = 0; j < n; j++)
        {
            int l = max(0, j - a[j]);
            int r = min(n-1, j + a[j]);
            fre[l]++;
            if(r+1 < n) fre[r+1]--;
}
for(int j = 0; j < n; j++)
{
    if(j != 0) fre[j] += fre[j-1];
}
a = fre;
}    

for(int i = 0; i < n; i++) cout << a[i] << " ";
        
}
