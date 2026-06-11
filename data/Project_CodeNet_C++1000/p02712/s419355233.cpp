    #include<bits/stdc++.h>
    using namespace std;
     
    #define fastIO() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define endl '\n'
     
    int main()
    {
     fastIO();
     long long n , fizbuzsum=0;
    // bool fizbuz = false;
     cin>>n;
     for(int i=1; i<=n; i++)
     {
     	if( (i%3 != 0) && (i%5 != 0) )
     	{
     	//	fizbuz = true;
     		fizbuzsum+=i;
    	 }
     }
    cout<<fizbuzsum<<endl;
    return 0;
    }