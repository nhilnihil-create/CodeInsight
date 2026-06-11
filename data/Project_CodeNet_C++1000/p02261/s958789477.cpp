#include<iostream>

using namespace std;

struct Card
{
    char suit;
    int value;
};

void bubbleSort( struct Card card[], int N )
{
    for( int i = 0; i < N; i++)
    {
        for( int j = N - 1; j > i; j--)
        {
            if( card[j].value < card[j - 1].value)
                swap( card[j], card[j-1] );
        }
    }
}

void selectionSort( struct Card card[], int N )
{
    for( int i = 0; i < N; i++)
    {
        int minj = i;
        for( int j = i; j < N; j++)
        {
            if( card[j].value < card[minj].value)
                minj = j;
        }
        swap( card[i], card[minj] );
    }
}

bool isStable( struct Card card1[], struct Card card2[], int N )
{
    for( int i = 0; i < N; i++)
    {
        if( card1[i].suit != card2[i].suit)
            return false;
    }

    return true;
}

int main()
{
    Card card1[100], card2[100];
    int N;

    cin >> N;
    for( int i = 0; i < N; i++ )
    {
        cin >> card1[i].suit >> card1[i].value;
    }

    for( int i = 0; i < N; i++ )
    {
        card2[i] = card1[i];
    }

    bubbleSort( card1, N );
    selectionSort( card2, N );
    
    for( int i = 0; i < N; i++)
    {
        cout << card1[i].suit << card1[i].value;
        if( i == N - 1 )
            cout << endl;
	else
            cout << ' ';
    }
    cout << "Stable" << endl;

    for( int i = 0; i < N; i++)
    {
        cout << card2[i].suit << card2[i].value;
        if( i == N - 1 )
            cout << endl;
	else
            cout << ' ';
    }

    if( isStable( card1, card2, N ) )
        cout << "Stable" << endl;
    else
        cout << "Not stable" << endl;

    return 0;
}