/**
        Bismilla- hir rahma-nir rahi-m
    @uthor Md Hasibur Rahman (Evan)
                JKKNIU
*/


#include<bits/stdc++.h>
#define         ll              long long
#define         FI              freopen("input.txt","r",stdin)
#define         FO              freopen("output.txt","w",stdout)
#define         PrintCase(i)    printf("Case %d: ",i)
#define         sc(a)           scanf("%d",&a)
#define         scl(a)          scanf("%lld",&a)
#define         rep(i,n)        for(int i=0;i<n;i++)
#define         pb              push_back
#define         MAX             1000000
#define         fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define			endl			"\n"


using namespace std;

bool isPrime(ll a)
{
    for(ll i=2;i*i<=a;i++)
        if(a%i==0)
            return false;
    return true;
}






bool isPowerOfTwo(ll a)
{
    if(a==1)
        return true;
    if(a&1)
        return false;
    while(a)
    {
        a/=2;
        if(a!=1 && a&1)
            return false;
        if(a==1)
            return true;
    }
    return true;
}




ll gcd(ll a, ll b)
{
    if(a<0 || b<0)
    {
        a = abs(a);
        b = abs(b);
    }
    if(a<b)
        swap(a,b);
    if(a%b==0 || b==0)
        return b;
    else
        return gcd(b,a%b);
}



ll lcm(ll a, ll b)
{
    return (a*b)/gcd(a,b);
}



ll power(ll base, ll exponent)
{
    ll ans = 1;
    for(ll i=1;i<=exponent;i++)
        ans*=base;
    return ans;
}




bool isPowerOfX(ll x, ll value)
{
    if(value==1)
        return true;
    while(value)
    {
        value/=x;
        if(value%x && value!=1)
            return false;
    }
    return true;
}


ll X_or(ll for1, ll for2, ll value)
{
	ll arr[7];
	arr[3] = for1^for2;
	//cout<<(for1^for2)<<endl;
	arr[4] = arr[3]^for2;
	arr[5] = arr[4]^arr[3];
	cout<<arr[3]<<" "<<arr[4]<<" "<<arr[5]<<" ..... \n";
	if(value%3==0)
	{
		//cout<<arr[]
		return arr[3];
	}
	else
	{
		ll ret = ((value%3)==1)?arr[4] : arr[5];
		return ret;
	}
}


ll X_nor(ll for1, ll for2, ll value)
{
	ll arr[7];
	arr[3] = ~(for1^for2);
	//cout<<~(for1^for2)<<endl;
	if(arr[3]<0)
		arr[3]*=(-1);
	arr[4] = ~(arr[3]^for2);
	if(arr[4]<0)
		arr[4]*=(-1);
	arr[5] = ~(arr[3]^arr[4]);
	if(arr[5]<0)
		arr[5]*=(-1);
	cout<<arr[3]<<" "<<arr[4]<<" "<<arr[5]<<" ..... \n";
	if(value%3==0)
	{
		return arr[3];
	}
	else
	{
		ll ret = (value%3==1)? arr[4] : arr[5];
		return ret;
	}
}





bool Visit[9999990];
int cnt[9999990];





int main()
{
	int n;
	cin>>n;
	rep(i,n)
	{
		int k;
		cin>>k;
		cnt[k]++;
	}
	int Co = 0;
	rep(i,9999990)
	{
		if(Visit[i] || cnt[i]==0)
		continue;
		if(cnt[i]==1 && !Visit[i])
			Co++;
		for(int j=i;j<9999990;j+=i)
			Visit[j] = true;		
	}
	cout<<Co<<endl;
	return 0;
}
