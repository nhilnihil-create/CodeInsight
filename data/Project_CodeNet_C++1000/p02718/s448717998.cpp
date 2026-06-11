#include<iostream>
#include<vector>
#include<algorithm>

int main(){
	int N, M;
	std::cin >> N >> M;


	int total{};
	std::vector<int> stuff(N,0);

	for( int i{}; i < N; ++i )
	{
		int t;
		std::cin >> t;
		total += t;
		stuff[i] = t;
	}

	
	const auto capable
		= std::count_if(
			std::cbegin( stuff )
			, std::cend( stuff )
		, [=]( const auto e )
		{
			return total <= 4 * M * e;
		}
	);

	std::cout << (capable>=M?"Yes":"No") << "\n";

	return 0;
}