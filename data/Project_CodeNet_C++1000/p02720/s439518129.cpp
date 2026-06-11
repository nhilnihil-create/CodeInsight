#include<iostream>
#include<queue>
#include<algorithm>

using ull = unsigned long long;

int main(){

	int K;
	std::cin >> K;

	std::queue<ull> queue_;

	for( int i{ 1 }; i <= 9; ++i )
		queue_.emplace( i );

	ull cnt_ = K;
	ull ans = 0;
	while( cnt_ > 0 )
	{
		const auto v = queue_.front();
		queue_.pop();
		--cnt_;
		//std::cout << v << ":" << cnt_ << "\n";
		if( cnt_ == 0 )
			ans = v;

		const auto a = v * 10 + v % 10;

		if( a % 10 != 0 )
			queue_.emplace( a - 1 );

		queue_.emplace( a );


		if( a % 10 != 9 )
			queue_.emplace( a + 1 );

	}
	//ans = queue_.front();

	std::cout << ( K <= 9 ? K : ans ) << "\n";

	return 0;
}