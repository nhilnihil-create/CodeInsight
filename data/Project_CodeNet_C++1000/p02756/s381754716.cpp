//According to all known laws of aviation, there is no way that a bee should be able to fly.
//Its wings are too small to get its fat little body off the ground. The bee, of course, flies anyway.
//Because bees don't care what humans think is impossible.
#include <bits/stdc++.h>
#define FAST_IO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define endl "\n"
 
using namespace std ;
using bigint = long long int ;
using vi = vector<int> ;
using vll = vector<long long int> ;

int main(){
    FAST_IO ;
    string str ; cin >> str ;
    int Q ; cin >> Q ;
    bool reversed = false ;
    deque<char> dq ( str.begin() , str.end() ) ;
    
    while( Q-- ){
        int x ; cin >> x ;
        if( x == 1 )
            reversed = !reversed ;
        else{
            int f ; cin >> f ; char ch ; cin >> ch ;
            if( f == 1 ){
                if( reversed )
                    dq.push_back(ch) ;
                else
                    dq.push_front(ch) ;
            }
            else{
                if( reversed )
                    dq.push_front(ch) ;
                else
                    dq.push_back(ch) ;
            }
        }
    }
    string ans = "" ;
    while( !dq.empty() ){
        char ch = dq.front() ;
        dq.pop_front() ;
        ans += ch ;
    }
    if( reversed ){
        reverse(ans.begin(), ans.end() ) ;
    }
    cout << ans << endl ;
    return 0 ;
}
