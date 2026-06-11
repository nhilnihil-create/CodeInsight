#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#define rep(i, n) for(int i=0; i < n; i++)

const long long INF = 1LL << 60;

/* bがa以上のとき、置き換え */
template<class T> inline bool chmax(T& a, T b){if(a < b){a = b;}else{return false;}return true;}

/* bがa以下のとき、置き換え */
template<class T> inline bool chmin(T& a, T b){if(a > b){a = b;}else{return false;}return true;}

int main()
{
	int N;
	std::cin >> N;
	std::map<std::string, int> name;
	
	rep(i, N)
	{
		std::string tmp;
		std::cin >> tmp;

		if( name.find(tmp) != name.end() )
		{
			name[tmp]++;
		}
		else
		{
			name.insert(std::make_pair(tmp, 1));
		}
	}
	
	// maxの回数を調べる
	int max = 0;
	for( std::pair<std::string, int> now: name )
	{
		int value = now.second;
		max = std::max( max, value );
	}

	// 出力する 
	for( std::pair<std::string, int> now: name )
	{
		if( now.second == max )
		{
			std::cout << now.first << std::endl;
		}
	}

	return 0;
}
