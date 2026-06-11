#include <iostream>

int main(int argc, char const* argv[])
{
	int mat_size, vec_size;
	int mat[100][100] = {};
	int vec[100] = {};

	std::cin >> mat_size >> vec_size;

	for (size_t i = 0; i < mat_size; i++)
		for (size_t j = 0; j < vec_size; j++)
			std::cin >> mat[i][j];

	for (size_t j = 0; j < vec_size; j++)
		std::cin >> vec[j];

	for (size_t i = 0; i < mat_size; i++)
	{
		int element_val = 0;
		for (size_t j = 0; j < vec_size; j++)
		{
			element_val += mat[i][j] * vec[j];
		}
    std::cout << element_val << std::endl;
	}

	return 0;
}