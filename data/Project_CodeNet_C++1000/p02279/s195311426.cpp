#include <bits/stdc++.h>
using namespace std;

template<typename T>
T gcd(T a, T b)
{
	return b ? gcd(b, a%b) : a;
}

template<typename T>
T lcm(T a, T b)
{
	return a / gcd(a, b) * b;
}

//(a^e)%mod
template<typename T>
T power(T a, T e, T mod)
{
	if(e == 0)
	{
		return 1;
	}
	if(e % 2 != 0)
	{
		//a^e=a^(e-1)*a
		return (power(a, e - 1, mod) * a) % mod;
	}
	T res = power(a, e / 2, mod);
	//a^e=a^(e/2)*a^(e/2)
	return (res * res) % mod;
}

template<typename T>
class Tree
{
private:
public:
	T data;
	Tree* parent = NULL;
	std::vector<Tree*> children;
	void setData(T x)
	{
		data = x;
	}
	void setParent(Tree* t)
	{
		parent = t;
	}
	void addChild(Tree* t)
	{
		children.push_back(t);
	}
	Tree* getParent()
	{
		return parent;
	}
	T getData()
	{
		return data;
	}
	Tree(){}
	~Tree(){}
	
};

int main()
{
	using namespace std;
	Tree<int> t[100001];
	int n, k, e, index;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> index >> k;
		t[index].setData(index);
		for (int j = 0; j < k; ++j)
		{
			cin >> e;
			t[e].setParent(&t[index]);
			t[index].addChild(&t[e]);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout << "node " << i << ": parent = ";
		if(t[i].getParent() != NULL)
		{
			cout << (t[i].getParent())->getData();
		}
		else
		{
			cout << -1;
		}
		cout << ", depth = ";
		int count = 0;
		for (auto a = t[i].getParent(); a != NULL; a = a->getParent())
		{
			++count;
		}
		cout << count << ", ";
		if(count == 0)
		{
			cout << "root";
		}
		else if((t[i].children).size() == 0)
		{
			cout << "leaf";
		}
		else
		{
			cout << "internal node";
		}
		cout << ", [";
		for (int j = 0; j < t[i].children.size(); ++j)
		{
			cout << (t[i].children[j]->getData());
			if(j < t[i].children.size()-1)
			{
				cout << ", ";
			}
		}
		cout << "]" << endl;
	}
	return 0;
}

