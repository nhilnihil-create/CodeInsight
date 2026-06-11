#include<bits/stdc++.h> 
typedef double ll;
#define pb push_back
#define MP make_pair

using namespace std;
int maxSum(int arr[], int n, int k) 
{ 
    // k must be greater 
    if (n < k) 
    { 
       cout << "Invalid"; 
       return -1; 
    } 
  
    // Compute sum of first window of size k 
    int res = 0; 
    for (int i=0; i<k; i++) 
       res += arr[i]; 
   
    int curr_sum = res; 
    int p=0;
    for (int i=k; i<n; i++) 
    { 
       curr_sum += arr[i] - arr[i-k];
       if(curr_sum>res)
       {
          p=i-k+1; 
       }
       res = max(res, curr_sum); 
    } 
  
    return p; 
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int p=maxSum(a, n, k);
   //cout<<p<<" ";
    double s=0,e=0;
     for(int i=p;i<p+k;i++)
    {
        int m=a[i];
        e=(double)(m+1);
        e=(double)e/2;
        s=(double)s+e;
        
    }
  cout<<fixed<<setprecision(12)<<s;
   
    

    
     
    
     return 0;
}
