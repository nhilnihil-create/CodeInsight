#include <iostream>
#include <string>
#include <vector>

//Declaration
class Card{
public:
    Card( const std::string str );
    char GetSymbol();
    int GetNumber();
    std::string GetString();

private:
    std::string pair;
};

void MySwap( Card& a, Card& b );
void BubbleSort( std::vector<Card>& vec );
void SelectionSort( std::vector<Card>& vec );
std::string CheckStable( std::vector<Card> initial, std::vector<Card> sorted );

int main(){
    //----Initialization Section----
    int n;
    std::cin >> n;
    std::string str;
    std::vector<Card> input;
    std::vector<Card> bubble;
    std::vector<Card> select;
    int i = 0;
    for( ; i < n; ++i ){
        std::cin >> str;
        input.push_back( Card(str) );
        bubble.push_back( Card(str) );
        select.push_back( Card(str) );
    }

    //----Sort Section----
    BubbleSort(bubble);
    SelectionSort(select);

    //----Output Section----
    for( i = 0; i < n; ++i ){
        std::cout << bubble[i].GetString() << ( ( i != n-1 )? " " : "" );
    }
    std::cout << "\n" << CheckStable( input, bubble ) << "\n";

    for( i = 0; i < n; ++i ){
        std::cout << select[i].GetString() << ( ( i != n-1 )? " " : "" );
    }
    std::cout << "\n" << CheckStable( input, select ) << std::endl;;
}

//Definition
Card::Card( const std::string str ){
    pair = str;
}

char Card::GetSymbol(){
    return pair[0];
}

int Card::GetNumber(){
    return static_cast<int>( pair[1] - '0' );
}

std::string Card::GetString(){
    return pair;
}

void MySwap( Card& a, Card& b ){
    Card tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}

void BubbleSort( std::vector<Card>& vec ){
    int n = vec.size();
    for( int i = 0; i < n; ++i ){
        for( int j = n - 1; j > i; --j ){
            if( vec[j].GetNumber() < vec[j-1].GetNumber() ){
                MySwap( vec[j], vec[j-1] );
            }
        }
    }
}

void SelectionSort( std::vector<Card>& vec ){
    int n = vec.size();
    int minj;
    int j;
    for( int i = 0; i < n; ++i ){
        minj = i;
        for( j = i; j < n; ++j ){
            if( vec[j].GetNumber() < vec[minj].GetNumber() ){
                minj = j;
            }
        }
        if( i != minj ){
            MySwap( vec[i], vec[minj] );
        }
    }
}  

std::string CheckStable( std::vector<Card> initial, std::vector<Card> sorted ){
    int N = sorted.size();
    for( int i = 0; i < N; ++i ){
        for( int j = i+1; j < N; ++j ){
            for( int a = 0; a < N; ++a ){
                for( int b = a+1; b < N; ++b ){
                    if( initial[i].GetNumber() == initial[j].GetNumber() &&
                        initial[i].GetString() == sorted[b].GetString() &&
                        initial[j].GetString() == sorted[a].GetString() ){
                            return "Not stable";
                    }
                }
            }
        }
    }
    return "Stable";
}
