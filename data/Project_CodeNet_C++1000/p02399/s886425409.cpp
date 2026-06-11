#include <cstdio>
using namespace std;

int main()
{

	int a, b;

	scanf( "%d %d", &a, &b );
	printf( "%d %d %lf\n", a / b, a % b, static_cast< double >(a) / static_cast< double >(b) );

	return 0;

}