#include <bits/stdc++.h>
using namespace std;
#define int long long
using vec_int = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int charToInt(char c){
    char zero_num = '0';
    return (int)c - (int)zero_num;
}

std::vector<int> Eratosthenes( const int N )
{
    std::vector<bool> is_prime( N + 1 );
    for( int i = 0; i <= N; i++ )
    {
        is_prime[ i ] = true;
    }
    std::vector<int> P;
    for( int i = 2; i <= N; i++ )
    {
        if( is_prime[ i ] )
        {
            for( int j = 2 * i; j <= N; j += i )
            {
                is_prime[ j ] = false;
            }
            P.emplace_back( i );
        }
    }
    return P;
}


signed main(){
    int N; cin>>N;

    int tot_num = 0;
    for(int j=1;j<N+1;j++){
        //交差がjで初項がlast_numの等差数列の和を考えればよい
        int last_num = j*(N/j);
        tot_num += (last_num + j) * (N/j)/2;

//        for(int i=1;i<N+1;i++){
//            if(i%j==0)tot_num +=i;
//        }
    }
    cout<<tot_num<<endl;



    return 0;
}