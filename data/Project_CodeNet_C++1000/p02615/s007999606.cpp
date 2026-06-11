    #include<algorithm>
    #include<iostream>
    using namespace std;
    int main()
    {
        long long n,i,j;
        long long ans=0;
        cin>>n;
      	long long a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        ans+=a[n-1];
        j=n-2;
        for(i=n-3;i>=0;)
        {
          if(i>=0)
          {
          ans+=a[j];
          i--;
          }
          if(i>=0)
          {
          ans+=a[j];
          i--;
          }
          j--;
        }
        cout<<ans<<endl;
      return(0);
    }