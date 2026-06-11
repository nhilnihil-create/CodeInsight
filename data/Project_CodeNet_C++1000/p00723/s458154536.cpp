#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

#define rep(idx, max)			for(int idx = 0, idx##Max = (max); idx < idx##Max; idx ++)
#define rrep(idx, min, max)	for(int idx = (min), idx##Max = max; idx < idx##Max; idx ++)
#define erep(idx, min, max)	for(int idx = (min), idx##Max = max; idx <= idx##Max; idx ++)

#define rev(idx, max)			for(int idx = (max) - 1; idx >= 0; idx --)
#define rrev(idx, min, max)	for(int idx = (max) - 1, idx##Min = (min); idx >= idx##Min; idx --)
#define erev(idx, min, max)	for(int idx = (max), idx##Min = (min); idx >= idx##Min; idx --)

typedef std::string	STR;

int Reverse(STR &dst)
{
	int len = dst.size();
	rep(i, dst.size() >> 1)
	{
		std::swap(dst[i], dst[len - 1 - i]);
	}
}

int main()
{
	int n;
	std::cin >> n;
	
	while(n --)
	{
		std::set<STR>	st;
		STR str;
		
		std::cin >> str;
		
		int len = str.size();
		rep(i, str.size() - 1)
		{
			STR s1 = str.substr(0, i + 1);
			STR s2 = str.substr(i + 1, len - 1 - i);
			STR r1 = s1;
			STR r2 = s2;
			Reverse(r1);
			Reverse(r2);
			
		/*	std::cout << "[*]" << s1 << "+" << s2 << std::endl;
			std::cout << s1 + s2 << std::endl;
			std::cout << s1 + r2 << std::endl;
			std::cout << r1 + s2 << std::endl;
			std::cout << r1 + r2 << std::endl;
			std::cout << s2 + s1 << std::endl;
			std::cout << s2 + r1 << std::endl;
			std::cout << r2 + s1 << std::endl;
			std::cout << r2 + r1 << std::endl;
		*/	st.insert(s1 + s2);
			st.insert(s1 + r2);
			st.insert(r1 + s2);
			st.insert(r1 + r2);
			st.insert(s2 + s1);
			st.insert(s2 + r1);
			st.insert(r2 + s1);
			st.insert(r2 + r1);
		}
		
//		for(std::set<STR>::iterator it = st.begin(), itEnd = st.end(); it != itEnd; it ++)
//		{	std::cout << *it << std::endl;	}
		std::cout << st.size() << std::endl;
	}
}