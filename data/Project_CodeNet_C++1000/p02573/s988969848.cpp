#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <functional>
#include <iterator>

using namespace std;
const long long INF = 1e18;

class UnionFind
{
public:
    static UnionFind Create(int iTotalNumber)
    {
        return UnionFind(iTotalNumber);
    }

    void Init(const int iTotalNum)
    {
        mParent.resize(iTotalNum);
        mRank.resize(iTotalNum);
        mSize.resize(iTotalNum);
        for (int i = 0; i < iTotalNum; i++)
        {
            mParent[i] = i;
            mRank[i] = 0;
            mSize[i] = 1;
        }
    }

    int FindParent(const int iRoot)
    {
        if (iRoot == mParent[iRoot])
        {
            return iRoot;
        }
        else
        {
            mParent[iRoot] = FindParent(mParent[iRoot]);
            return mParent[iRoot];
        }
    }

    void UniteGroup(const int iRoot1, const int iRoot2)
    {
        int parent1 = this->FindParent(iRoot1);
        int parent2 = this->FindParent(iRoot2);
        if (parent1 == parent2) return;

        if (mRank[parent1] < mRank[parent2])
        {
            mParent[parent1] = parent2;
            mSize[parent2] = mSize[parent1] + mSize[parent2];
        }
        else if (mRank[parent2] < mRank[parent1])
        {
            mParent[parent2] = parent1;
            mSize[parent1] = mSize[parent1] + mSize[parent2];
        }
        else if (mRank[parent2] == mRank[parent1])
        {
            mParent[parent2] = parent1;
            mSize[parent1] = mSize[parent1] + mSize[parent2];
            mRank[parent2]++;
        }
        //else should never happen
    }

    bool AreInTheSameGroup(const int iRoot1, const int iRoot2)
    {
        return FindParent(iRoot1) == FindParent(iRoot2);
    }

    int GetGroupSize(int iRoot)
    {
        int parent = FindParent(iRoot);
        return mSize[parent];
    }

    int GetMaxTreeSize() 
    {
        int maxSize = -1;
        for (const auto& parent : mParent)
        {
            maxSize = max(maxSize, GetGroupSize(parent));
        }
        return maxSize;
    }

private:
    UnionFind(int iTotalNumber)
    {
        this->Init(iTotalNumber);
    }


    std::vector<int> mParent;
    std::vector<int> mRank;
    std::vector<int> mSize;
};

int main(void)
{
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    vector<int> B(M);
    UnionFind uf = UnionFind::Create(N);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        A[i] = a-1;
        B[i] = b-1;
        uf.UniteGroup(A[i], B[i]);
    }

    cout << uf.GetMaxTreeSize() << endl;
   
    return 0;
}