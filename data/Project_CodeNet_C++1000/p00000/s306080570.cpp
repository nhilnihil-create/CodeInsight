//ツ暗按可コツづ個フツォツーツマツッツトツづ可従ツづづ出ツ療債づーツつケツづヲツ　ツ禿シツ療債づ債づ按つ「
//1x1=1
//1x2=2
//.
//.
//9x8=72
//9x9=81

#include<iostream>
using namespace std;

int main(void)
{
	int l, r;
	for(int i = 0; i < 81; i++)
	{
		l = i/9+1;
		r = i%9+1;
		cout << l << 'x' << r << '=' << l*r << endl;
	}
	return 0;
}