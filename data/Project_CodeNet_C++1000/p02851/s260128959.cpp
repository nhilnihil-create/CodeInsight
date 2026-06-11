// È¥°É£¡Æ¤¿¨Çð! °ÑAC´ø»ØÀ´£¡
//      ¤Ø¡¡¡¡¡¡¡¡¡¡£¯|
// ¡¡¡¡/£Ü7¡¡¡¡¡¡ ¡Ï£ß/
// ¡¡ /¡¡©¦¡¡¡¡ £¯¡¡£¯								AC		AC		AC		AC
//    ©¦¡¡Z £ß,£¼¡¡£¯¡¡¡¡ /`©c						AC		AC		AC		AC
//    ©¦¡¡¡¡¡¡¡¡¡¡©c¡¡¡¡ /¡¡¡¡¡µ					AC		AC		AC		AC
// ¡¡Y¡¡¡¡¡¡¡¡¡¡`¡¡ /¡¡¡¡/  /						AC		AC		AC		AC
// ¡¡Øé¡ñ¡¡.¡¡¡ñ¡¡¡¡¡´¡¡/¡¡/						AC		AC		AC		AC
// ¡¡()¡¡ ¤Ø¡¡¡¡¡¡¡¡|¡¡£Ü¡´							AC		AC		AC		AC
// ¡¡¡¡>- ._¡¡ ¥£¡¡ ©¦ £¯£¯							AC		AC		AC		AC
// ¡¡ / ¤Ø¡¡¡¡ /¡¡/£¼| £Ü£Ü							AC		AC		AC		AC
// ¡¡ ©c_/¡¡¡¡(_£¯¡¡ ©¦£¯£¯							AC		AC		AC		AC
// ¡¡¡¡ 7¡¡¡¡¡¡¡¡¡¡¡¡¡¡|£¯							AC		AC		AC		AC
// ¡¡¡¡ £¾¨Dr£þ£þ`-¨D£ß/							AC		AC		AC		AC
//**************************************Accepted*****************************************//

#include<bits/stdc++.h>

#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define Unique(x) x.erase(unique(all(x)),x.end());

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

#define Pig (OO)

using namespace std;

const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};

inline int read()
{
	#define gc getchar
	int ans=0;
	bool f=1;
	char ch=gc();
	
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	
	return f?ans:-ans;
	
	#undef gc
}

typedef long long ll;

/*

template <typename T>
struct modular {
    constexpr modular() : val(0){}
    constexpr modular(const modular<T>& _m) : val(_m.val) {}
    template <typename U> constexpr modular(const U& _r = U()) {
        val = -MOD <= _r && _r < MOD ? _r: _r % MOD;
        if (val < 0) { val += MOD; } }
    const T operator()() { return val; }
    template <typename U> explicit operator U() const { return static_cast<U>(val); }
    modular<T>& operator+=(const modular<T>& _m) { if ((val += _m.val) >= MOD) { val -= MOD; } return *this; }
    modular<T>& operator-=(const modular<T>& _m) { if ((val -= _m.val) < 0) { val += MOD; } return *this; }
    modular<T>& operator*=(const modular<T>& _m) { val = modular<T>(static_cast<int64_t>(val) * static_cast<int64_t>(_m.val)).val; return *this; }
    modular<T>& operator/=(const modular<T>& _m) {
        T a = _m.val, b = MOD, u = 0, v = 1;
        while (a != 0) {
            T q = b / a;
            b -= q * a; swap(a, b);
            u -= q * v; swap(u, v);
        } return *this *= u; }
    modular<T>& operator =(const modular<T>& _m) { val = _m.val; return *this; }
    template <typename U> modular<T>& operator+=(const U& _r) { return *this += modular<T>(_r); }
    template <typename U> modular<T>& operator-=(const U& _r) { return *this -= modular<T>(_r); }
    template <typename U> modular<T>& operator*=(const U& _r) { return *this *= modular<T>(_r); }
    template <typename U> modular<T>& operator/=(const U& _r) { return *this /= modular<T>(_r); }
    template <typename U> modular<T>& operator =(const U& _r) { val = modular<T>(_r).val; return *this; }
    modular<T> operator-() { return modular<T>(-val); }
    template <typename U> friend bool operator==(const modular<U>&, const modular<U>&);
    friend std::istream& operator>>(std::istream& os, modular<T>& _m) { os >> _m.val; _m *= 1; return os; }
    friend std::ostream& operator<<(std::ostream& os, const modular<T>& _m) { return os << _m.val; }
    template <typename U>
    modular<T> exp(U e) {
        modular<T> res = 1;
        modular<T> b = val;
        if (e < 0) { b = 1/b; e *= -1; }
        for (; e; e >>= 1) {
            if (e & 1) { res *= b; }
            b *= b;
        } return res; }
private:
    T val;
};
template <typename T> inline modular<T> operator+(const modular<T>& _lhs, const modular<T>& _rhs) { return modular<T>(_lhs) += _rhs; }
template <typename T, typename U> inline modular<T> operator+(const modular<T>& _lhs, const U& _rhs) { return modular<T>(_lhs) += _rhs; }
template <typename T, typename U> inline modular<T> operator+(const U& _lhs, const modular<T>& _rhs) { return modular<T>(_lhs) += _rhs; }
template <typename T> inline modular<T> operator-(const modular<T>& _lhs, const modular<T>& _rhs) { return modular<T>(_lhs) -= _rhs; }
template <typename T, typename U> inline modular<T> operator-(const modular<T>& _lhs, const U& _rhs) { return modular<T>(_lhs) -= _rhs; }
template <typename T, typename U> inline modular<T> operator-(const U& _lhs, const modular<T>& _rhs) { return modular<T>(_lhs) -= _rhs; }
template <typename T> inline modular<T> operator*(const modular<T>& _lhs, const modular<T>& _rhs) { return modular<T>(_lhs) *= _rhs; }
template <typename T, typename U> inline modular<T> operator*(const modular<T>& _lhs, const U& _rhs) { return modular<T>(_lhs) *= _rhs; }
template <typename T, typename U> inline modular<T> operator*(const U& _lhs, const modular<T>& _rhs) { return modular<T>(_lhs) *= _rhs; }
template <typename T> inline modular<T> operator/(const modular<T>& _lhs, const modular<T>& _rhs) { return modular<T>(_lhs) /= _rhs; }
template <typename T, typename U> inline modular<T> operator/(const modular<T>& _lhs, const U& _rhs) { return modular<T>(_lhs) /= _rhs; }
template <typename T, typename U> inline modular<T> operator/(const U& _lhs, const modular<T>& _rhs) { return modular<T>(_lhs) /= _rhs; }
template <typename T> inline bool operator==(const modular<T>& _lhs, const modular<T>& _rhs) { return _lhs.val == _rhs.val; }
template <typename T, typename U> inline bool operator==(const modular<T>& _lhs, const U& _rhs) { return _lhs == modular<T>(_rhs); }
template <typename T, typename U> inline bool operator==(const U& _lhs, const modular<T>& _rhs) { return modular<T>(_lhs) == _rhs; }
template <typename T> inline bool operator!=(const modular<T>& _lhs, const modular<T>& _rhs) { return !(_lhs == _rhs); }
template <typename T, typename U> inline bool operator!=(const modular<T>& _lhs, const U& _rhs) { return !(_lhs == _rhs); }
template <typename T, typename U> inline bool operator!=(const U& _lhs, const modular<T>& _rhs) { return !(_lhs == _rhs); }
typedef modular<int> mint;

*/

map<ll,ll> cnt;
ll n,k;
ll a[200010];

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	
	cin>>n>>k;
	cnt[0]=1ll;
	
	ll ans=0ll;
	
	for(ll i=1ll;i<=n;i++)
	{
		if(i>=k)cnt[a[i-k]]--;
		
		ll x;
		cin>>x;
		
		a[i]=(a[i-1]+x-1)%k;
		
		ans+=cnt[a[i]]++;
	}
	
	cout<<ans;
	
	//printf("Time used = %.12f",(double)(clock())/CLOCKS_PER_SEC);
	return 0;
}

/*  GOD BLESS  */
