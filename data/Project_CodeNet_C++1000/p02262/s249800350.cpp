#include<iostream>
#include<vector>

using namespace std;

long count = 0;
vector<int> G;
int exInsertionSort( int A[], int N, int g)
{
    if( g < 1 )
        return g;
    
    for( int i = g; i < N; i++)
    {
        int v = A[i];
        int j = i - g;
	while( j >= 0 && A[j] > v )
        {
            A[j + g] = A[j];
	    j -= g;
	    count++;
        }

        A[j + g] = v;
    }
    return 1;
}

void shellSort( int A[], int N )
{
    for( int h = 1; h <= N; h = 3 * h + 1 )
    {
        G.push_back(h);
    }

    for( int i = G.size() - 1; i >= 0; i--)
    {
        exInsertionSort( A, N, G[i] );
    }
}

int main()
{
    int N;
    int A[1000000];

    cin >> N;

    for( int i = 0; i < N; i++)
        cin >> A[i];

    shellSort( A, N );

    cout << G.size() << endl;

    for( int i = G.size() - 1; i >= 0; i-- )
    {
        cout << G[i];
	if( i )
            cout << ' ';
    }

    cout << endl;

    cout << count << endl;

    for ( int i = 0; i < N; i++ )
    {
        cout << A[i] << endl;
    }

    return 0;
}