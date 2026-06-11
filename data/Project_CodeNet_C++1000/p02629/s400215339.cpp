    #include<bits/stdc++.h>
    #define fast {ios_base::sync_with_stdio(false);cin.tie(NULL);}
    #define pb push_back
    typedef long long int ll;
    using namespace std;
    int main(void){
    	fast;
    	ll n;
    	cin>>n;
    	string ans="";
    	while(n!=0){
    		n--;
    		char c=(char)(n%26+'a');
    		string add(1,c);
    		ans=add+ans;
    		n/=26;
    	}
    	cout<<ans<<endl;
    }
