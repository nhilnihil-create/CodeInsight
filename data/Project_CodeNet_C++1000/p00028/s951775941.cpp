#include<iterator>
#include<algorithm>
#include<vector>
#include<map>
#include<iostream>
auto main ( ) -> int
{
    using namespace std ;
    vector < int > ns ;
    copy ( istream_iterator < int > { cin } , istream_iterator < int > { } , back_inserter ( ns ) ) ;
    map < int , int > table ;
    for ( auto n : ns )
    {
        auto table_find = table.find ( n ) ;
        if ( table_find != table.end ( ) )
	{
            ++ table_find->second ;
	}
	else
	{
            table [ n ] = 1 ;
	}
    }
    vector < pair < int , int > > sorted_table ;
    for ( auto p : table )
    {
        sorted_table.emplace_back ( p.second , p.first ) ;
    }
    sort ( sorted_table.rbegin ( ) , sorted_table.rend ( ) , [ ] ( pair < int , int > p1 , pair < int , int > p2 ) { return make_pair ( p1.first , p2.second ) < make_pair ( p2.first , p1.second ) ; } ) ;
    sorted_table.erase ( remove_if ( sorted_table.begin ( ) , sorted_table.end ( ) , [ sorted_table ] ( pair < int , int > p ) { return p.first < sorted_table [ 0 ].first ; } ) , sorted_table.end ( ) ) ;
    for ( auto p : sorted_table )
    {
        cout << p.second << endl ; 
    }
}