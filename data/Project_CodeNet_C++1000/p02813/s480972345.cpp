//                                 Alisher_2211
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        # include <bits/stdc++.h>
# define  long          long long
# define  all(vc)       vc.begin(),vc.end()
# define  allr(vc)      vc.rbegin(),vc.rend()
# define  pb            push_back
# define  fi            first 
# define  se            second
# define  pi            pair <long, long>    
# define  lcm(a, b)     (a * b) / __gcd(a, b)
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        using namespace std;
const long N = 100100;
void read(){freopen("input.txt" , "r" , stdin );freopen("output.txt", "w" , stdout );}
void solve(){
    long n;
    cin >> n;
    string p = "", q = "", s = "";
    vector <long> v(n), vc(n);
    for(auto &i: v){
        cin >> i;
        p += i + '0';
    }
    for(auto &i: vc){
        cin >> i;
        q += i + '0';
    }
    for (int i = 1; i <= n; ++i) s += i + '0';
    long a = -1, b = -1, res = 0;
    do{
        res ++;
        if( a == -1 && s == p ) a = res;
        if( b == -1 && s == q ) b = res;
        if( a > -1 && b > -1 ) break;
    }while(next_permutation( all(s) ));
    cout << abs(a - b);
}
int32_t main(){
ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
        long T = 1;
        //cin >> T;
        while( T-- ){
            solve();
            cout<<'\n';
        }
cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}