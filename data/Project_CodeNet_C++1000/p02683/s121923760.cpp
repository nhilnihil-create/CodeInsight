#include<iostream>
#include<vector>
#include<cstring>
#include<sstream>
#include<algorithm>
#include<iomanip>

using std::cout;
using std::endl;
using std::flush;
using std::cin;

namespace Util{
    using StringVector = std::vector<std::string>;

    /*
       @ 目的: 文字列分割
    */
    StringVector split( const std::string &s, const std::string &delim = std::string(" ") ){
       const int len = s.size();
       char tmp[len+1];
       strcpy( tmp, s.c_str() );

       std::vector<std::string> res;

       char *tmpStr = std::strtok( tmp, delim.c_str() );
       if( tmpStr == NULL ) return res;

       while( tmpStr != NULL ){
           //cout << tmpStr << endl;
           res.push_back( tmpStr );
           tmpStr = NULL;
           tmpStr = std::strtok( NULL, " " );
       }
    return res;
    }

    /*
       @ 目的: 数字等を文字列に固める
    */
    template<typename T>
    std::string toString( T data, int width = 0 ){
       std::stringstream ss;
       ss << std::setw(width) << data;
    return ss.str();
    }
    template<> std::string toString( bool flg, int width ){
       if( width == 1 && flg ) return std::string("T");
       if( width == 1 && !flg ) return std::string("F");
       if( flg ) return std::string("true");
    return std::string("false");
    }
}


namespace Original{
    using Data  = std::vector<int>;
    using Table = std::vector< Data >;
}

int main( void ){
    cin.tie(0);
    std::ios::sync_with_stdio(false);

    // めちゃくちゃな値をセットしておく
    const int INF = 123456789;

    // n, m, x をそれぞれ取得
    std::string tmpNum;
    std::getline( cin, tmpNum );
    Util::StringVector t = Util::split( tmpNum );
    int n = std::atoi( t[0].c_str() );
    int m = std::atoi( t[1].c_str() );
    int x = std::atoi( t[2].c_str() );

    // テーブルとして取得( 二次元配列風 )
    Original::Table table;
    for( int i = 0; i < n; i++ ){
         std::string s;
         getline( cin, s );
         Util::StringVector sv = Util::split( s );
         Original::Data d;
         for( int j = 0; j < m+1; j++ ){
              d.push_back( std::atoi( sv[j].c_str() ) );
         }
         table.push_back( d );
    }

    // 初期値は INFとする
    int ans = INF;

    // bit全探索
    for( int bit = 0; bit < (1 << n); bit++ ){
         std::vector<int> vec(m+1,0);
         for( int i = 0; i < n; i++ ){
              if( (bit >> i) & 1 ){
                  vec[0] += table[i][0];
                  for( int j = 1; j <= m; j++ ) vec[j] += table[i][j];
              }
         }

         bool isAllowed = true;
         for( int i = 1; i <= m; i++ ){
              // todo: もしエラーなら "<=" とかにしてみる
              if( vec[i] < x ){ isAllowed = false; break; }
         }

         if( isAllowed ) ans = std::min( ans, vec[0] );
    }

    if( ans == INF ) cout << -1 << endl;
    else             cout << ans << endl;
return 0;
}