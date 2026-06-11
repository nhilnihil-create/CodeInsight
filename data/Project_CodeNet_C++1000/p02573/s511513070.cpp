#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>
#include <new>
#include <typeinfo>
#include <iterator>
#include <cassert>

using ll = long long;
using ull = unsigned long long;
constexpr ll mop = 1000000007;
constexpr ll mop2 = 998244353;

using namespace std;

constexpr ll NOT_SPECIFIED_VALUE_MIN = INT64_MIN;
constexpr ll NOT_SPECIFIED_VALUE_MAX = INT64_MAX;


int main()
{
	ll numNode, numEdge;
	cin >> numNode >> numEdge;
	vector<bool> discovered( numNode + 1, false );

	vector<vector<ll>> adjacentList(numNode + 1);
	for( ll i = 0; i < numEdge; i++ )
	{
		ll a, b;
		cin >> a >> b;
		adjacentList[a].push_back( b );
		adjacentList[b].push_back( a );
	}

	ll largestGroupSize = 0;
	for( ll i = 1; i <= numNode; i++ )
	{
		if( discovered[i] == true )
		{
			continue;
		}

		ll tmpGroupSize = 0;
		queue<ll> Q;
		Q.push( i );
		discovered[i] = true;
		tmpGroupSize++;
		while( !Q.empty() )
		{
			ll nowNode = Q.front();
			Q.pop();
			for( auto adjacent : adjacentList[nowNode] )
			{
				if( discovered[adjacent] == false )
				{
					Q.push( adjacent );
					discovered[adjacent] = true;
					tmpGroupSize++;
				}
			}
		}
		if( tmpGroupSize > largestGroupSize )
		{
			largestGroupSize = tmpGroupSize;
		}
	}
	cout << largestGroupSize << endl;

}
