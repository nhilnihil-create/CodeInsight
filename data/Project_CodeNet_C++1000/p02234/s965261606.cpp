#include <climits>
#include <iostream>
#include <vector>

struct TMatrix
{
	int Row;
	int Col;
	
	TMatrix(int ARow, int ACol);
};

TMatrix::TMatrix(int ARow, int ACol)
: Row(ARow), Col(ACol)
{
}

class TMinimumMultiplications
{
	std::vector<std::vector<int> > FTable;
	const std::vector<TMatrix>& FMatrixChain;
	
	int GetMinimum(int Begin, int End);
public:
	TMinimumMultiplications(const std::vector<TMatrix>& MatrixChain);
	
	int Get(int Begin, int End);
};

TMinimumMultiplications::TMinimumMultiplications(const std::vector<TMatrix>& MatrixChain)
: FMatrixChain(MatrixChain), FTable(MatrixChain.size(), std::vector<int>(MatrixChain.size(), -1))
{
}

int TMinimumMultiplications::GetMinimum(int Begin, int End)
{
	int Minimum = INT_MAX;
	for(int i = Begin; i < End; ++i){
		int Total = Get(Begin, i)
		          + Get(i + 1, End)
		          + FMatrixChain[Begin].Row * FMatrixChain[i + 1].Row * FMatrixChain[End].Col;
		if(Minimum > Total) Minimum = Total;
	}
	return Minimum;
}

int TMinimumMultiplications::Get(int Begin, int End)
{
	if(Begin == End) return 0;
	if(FTable[Begin][End] < 0){
		FTable[Begin][End] = GetMinimum(Begin, End);
	}
	return FTable[Begin][End];
}

int MinimumMultiplicationCount(const std::vector<TMatrix>& MatrixChain)
{
	TMinimumMultiplications Minimum(MatrixChain);
	return Minimum.Get(0, MatrixChain.size() - 1);
}

int main()
{
	int Count;
	std::cin >> Count;
	std::vector<TMatrix> MatrixChain;
	for(int i = 0; i < Count; ++i){
		int Row, Col;
		std::cin >> Row >> Col;
		MatrixChain.push_back(TMatrix(Row, Col));
	}
	
	std::cout << MinimumMultiplicationCount(MatrixChain) << std::endl;
	return 0;
}