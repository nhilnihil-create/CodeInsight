#include<iostream>
#include<map>
#include<string>

std::map<std::string,int> m;

int main()
{
	std::string s;
	std::getline( std::cin, s );
	
	int b = 0, e = 0;
	
	for( int i = 0; i < s.size(); i++ ){
		if( s[i] != ' ' ) e++;
		else{
			std::string s2 = s.substr( b, e - b );
			b = ++e;
			e = b;
			
		 	if( m.find( s2 ) != m.end() ){
				m.find( s2 )->second++;
			}
			else{
			 	m.insert( std::make_pair<std::string,int>( s2, 1 ) );
			}
		}
	}
	
	std::string s2 = s.substr( b, e - b + 1 );
	if( m.find( s2 ) != m.end() ){
		m.find( s2 )->second++;
	}
	else{
	 	m.insert( std::make_pair<std::string,int>( s2, 1 ) );
	}
	
	int len = 0, count = 0;
	for( std::map<std::string,int>::iterator it = m.begin(); it != m.end(); it++ ){
		count = std::max( count, it->second );
		len = std::max( len, (int)it->first.size() );
	}
	
	for( std::map<std::string,int>::iterator it = m.begin(); it != m.end(); it++ ){
		if( count == it->second ){
			std::cout << it->first << " ";
		}
	}
	for( std::map<std::string,int>::iterator it = m.begin(); it != m.end(); it++ ){
		if( len == it->first.size() ){
			std::cout << it->first << std::endl;
		}
	}
	
 	return 0;
}